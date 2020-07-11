#include<bits/stdc++.h>
using namespace std;
map<pair<string,char> , string > new_move;
void __init()
{
    new_move[make_pair("down",'D')] = "left";
    new_move[make_pair("down",'E')] = "right";

    new_move[make_pair("up",'D')] = "right";
    new_move[make_pair("up",'E')] = "left";

    new_move[make_pair("left",'D')] = "up";
    new_move[make_pair("left",'E')] = "down";

    new_move[make_pair("right",'D')] = "down";
    new_move[make_pair("right",'E')] = "up";

}
pair< int , int > new_index(pair< int , int > current_index, string _move)
{
    if(_move=="left")
        current_index.second-=1;
    else if(_move=="right")
        current_index.second+=1;
    else if(_move=="down")
        current_index.first+=1;
    else
        current_index.first-=1;

    return current_index;
}
int main()
{
    #ifdef TarekHasan
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif // TarekHasan

    int row, column , instruction_length;
    __init();

    while(cin >> row >> column >> instruction_length && row && column && instruction_length)
    {

        string _move;
        pair< int , int > robot_position;

        char grid[row][column];

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                cin >> grid[i][j];

                if(grid[i][j]=='N' || grid[i][j]=='O' || grid[i][j]=='L' || grid[i][j]=='S' )
                {
                    robot_position = make_pair(i,j);
                    if(grid[i][j]=='N')
                        _move="up";
                    else if(grid[i][j]=='O')
                        _move="left";
                    else if(grid[i][j]=='L')
                        _move="right";
                    else
                        _move="down";
                }
            }
        }
        string instruction; cin >> instruction;
        int counter = 0;

        for(char c : instruction)
        {
            if(c=='D' || c=='E')
                _move = new_move[{_move,c}];
            else
            {
                pair< int , int > temp = new_index(robot_position,_move);

                if((temp.first>=0 && temp.first<row) && (temp.second>=0 && temp.second<column) && grid[temp.first][temp.second]!='#')
                {
                    robot_position=temp;
                    if(grid[robot_position.first][robot_position.second]=='*')
                    {
                        counter++;
                        grid[robot_position.first][robot_position.second]='.';
                    }
                }

            }
        }

        cout << counter << endl;
    }

    return 0;
}
