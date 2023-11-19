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
            switch (Game_Type)
            {
                case Singleplayer:
                    Game_Loop_Turn_handler(& playersturn);

                case Multiplayer:
                    Online_Start_Correct_Protocol();
                    Game_Loop_Turn_handler(& playersturn);
            }
            Is_Game_Finished=true;
        }
        return 0;
    }
    void Game_Manager::Game_Loop_Turn_handler(int * playersturn)
    {

                if (*playersturn == 0)
                {
                    std::cout << "PLAYER 1" << std::endl;
                    PlayerVector[*playersturn]->print_map(*PlayerVector[*playersturn]->map, 0);
                    PlayerVector[*playersturn]->print_map(*PlayerVector[*playersturn]->map, 1);

                    PlayerVector[*playersturn]->Current_Player_Attack_Enemy(*PlayerVector[*playersturn],
                                                                            *PlayerVector[*playersturn + 1]);
                    *playersturn = 1;
                } else {
                    std::cout << "PLAYER 2" << std::endl;
                    PlayerVector[*playersturn]->print_map(*PlayerVector[*playersturn]->map, 0);
                    PlayerVector[*playersturn]->print_map(*PlayerVector[*playersturn]->map, 1);

                    PlayerVector[*playersturn]->Current_Player_Attack_Enemy(*PlayerVector[*playersturn],
                                                                            *PlayerVector[*playersturn - 1]);
                    *playersturn = 0;
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
                set_Game_Type(0);//TCP server must be started;
            }
            else
            {
                set_Game_Type(1);//TCP server must be started;
            }
        }
        else
        {
            set_Game_Type(2);//TCP client must be started;
        }
    }
    bool Game_Manager::Online_Start_Correct_Protocol()
    {
        switch (Game_Type)
        {
            case 1:
                Server =new Tcp_Server_Socket;
                std::cout << "you are hosting on the ip: "<< "this will show the ip" <<"on port:" << Server->get_port() << std::endl;
                Online_waiting_on_connection();
                break;
            case 2:
                Client =new Tcp_Client_Socket;
                break;
        }
        return false;
    }
    bool Game_Manager::Online_waiting_on_connection()
{
    std::thread t1(&Game_Manager::Extra_Dots_Loading_Screen, this, std::ref(*Server));
    if(Server->set_connection(*Server))
    {
        t1.join();
        return true;
    }
    return false;
}

    void Game_Manager::Extra_Dots_Loading_Screen(Tcp_Server_Socket& server)
{
    while (!server.get_Connection_Bind())
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

//initialization & destruction
    void Game_Manager::Init_Players()
    {
        Game_Player * player1 =new Game_Player;
        Game_Player * player2 =new Game_Player;

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
        if (Game_Type==1)
        {
            delete Server;
        }
        else { delete Client; }
    }


