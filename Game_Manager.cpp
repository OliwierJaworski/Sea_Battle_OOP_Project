#include "Game_Manager.h"

//constructor | destructor
    Game_Manager::Game_Manager()
    {
        Init_Players();
    }
    Game_Manager::~Game_Manager()
    {
       Free_Alloc();
    }

//public | private

//Game Core structure
    int Game_Manager::Game_Loop()
    {
        Online_Ask_Game_Type();

        bool Is_Game_Finished = false;
        int playersturn = 0;

        if(Game_Type== Multiplayer_host ||Game_Type== client )
        {
            Online_Start_Correct_Protocol();
        }

        while (!Is_Game_Finished)
        {
            //check for win condition
            for (auto & playeriterator : PlayerVector)
            {
                if (playeriterator->Get_Player_Status())
                {
                    std::cout << "player called (moet nog implementeren) has lost " << std::endl;
                    return 0;
                }
            }
            Game_Loop_Turn_handler(& playersturn);
            return 0;                                                                      // this is stopping the loop dont forget!!
        }
        return 0;
    }
    void Game_Manager::Game_Loop_Turn_handler(int * playersturn)
    {
        switch (Game_Type)
        {
            case Singleplayer:

                if (*playersturn == 0)
                {
                    std::cout << "PLAYER 1" << std::endl;
                    PlayerVector[*playersturn]->print_map(*PlayerVector[*playersturn]->map, 0);
                    PlayerVector[*playersturn]->print_map(*PlayerVector[*playersturn]->map, 1);

                    PlayerVector[*playersturn]->Current_Player_Attack_Enemy(*PlayerVector[*playersturn],
                                                                            *PlayerVector[*playersturn + 1]);
                    *playersturn = 1;
                } else
                {
                    std::cout << "PLAYER 2" << std::endl;
                    PlayerVector[*playersturn]->print_map(*PlayerVector[*playersturn]->map, 0);
                    PlayerVector[*playersturn]->print_map(*PlayerVector[*playersturn]->map, 1);

                    PlayerVector[*playersturn]->Current_Player_Attack_Enemy(*PlayerVector[*playersturn],
                                                                            *PlayerVector[*playersturn - 1]);
                    *playersturn = 0;
                }
                break;

            case Multiplayer_host:
                    //debug print player map
                    PlayerVector[1]->print_map(*PlayerVector[1]->map,0);
                    //send player 1 map
                    Online_Send_Client_Map();
                    //attack
                break;

            case client:
                std::cout << "setting map" <<std::endl;
                PlayerVector[0]->map->Online_Set_my_map(Client->Get_Array_Format(0));
                std::cout << "map is set" <<std::endl;
                PlayerVector[0]->print_map(*PlayerVector[0]->map,0);
                //ask for my map
                //
                break;
        }
    }
//extra added functionality
    void Game_Manager::Online_Ask_Game_Type()
    {
     std::string Is_Player_Host;

     std::cout << "are you hosting the game" << std::endl;
        do
        {
            std::cout << "yes or no only!" << std::endl;
            std::cin>>Is_Player_Host;
        }
        while(Is_Player_Host!="yes" && Is_Player_Host!="no");

        if(Is_Player_Host=="yes")
        {
            std::cout << "singleplayer or multiplayer?" << std::endl;
            do
            {
                std::cin>>Is_Player_Host;
            }
            while(Is_Player_Host!="singleplayer" && Is_Player_Host!="multiplayer");
            if(Is_Player_Host=="singleplayer")
            {
                set_Game_Type(Singleplayer);//local game will start
            }
            else
            {
                set_Game_Type(Multiplayer_host);//TCP server must be started;
            }
        }
        else
        {
            set_Game_Type(client);//TCP client must be started;
        }
    }
    bool Game_Manager::Online_Start_Correct_Protocol()
    {
        switch (Game_Type)
        {
            case Multiplayer_host:
                Server =new SBN::Tcp_Server_Socket;
                return Online_waiting_on_connection();
                break;
            case client:
                Client =new SBN::Tcp_Client_Socket;
                //                                                                                              !!!!!!!!!!!!!!!niet vergeten moet meer komen
                break;
        }
        return false;
    }
    bool Game_Manager::Online_waiting_on_connection()
    {
        std::thread t1(&Game_Manager::Extra_Dots_Loading_Screen, this, std::ref(*Server));
        if(Server->get_Client_socket_state()>0)
        {
            t1.join();
            return true;
        }
        return false;
    }

    void Game_Manager::Extra_Dots_Loading_Screen(SBN::Tcp_Server_Socket& server)
{
    while (Server->get_Client_socket_state()<=0)
    {
        std::system("clear");
        std::string dots = "";

        for (int i = 0; i < 3; ++i)
        {
            dots.append(".");
            std::cout << dots << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::system("clear");
        }
    }
}

//experimental
void Game_Manager::Online_Send_Client_Map()
{
    std::string Client_Map;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            Client_Map+=std::to_string(PlayerVector[1]->map->get_my_map(i,j));
        }
    }
    Server->send(Server->get_Client_socket_state(),Client_Map);
}

//initialization & destruction
    void Game_Manager::Init_Players()
    {

            Game_Player *player1 = new Game_Player;
            Game_Player *player2 = new Game_Player;

            PlayerVector.push_back(player1);
            PlayerVector.push_back(player2);
    }
    void Game_Manager::Free_Alloc()
    {
        for (auto & i : PlayerVector)
        {
            delete i;
        }
        PlayerVector.clear();
        PlayerVector.shrink_to_fit();

        if (Game_Type==Multiplayer_host)
        {
            delete Server;
        }
        if(Game_Type== client)
        {
            delete Client;
        }
    }


