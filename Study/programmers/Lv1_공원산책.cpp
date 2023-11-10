#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<int> start;
    int h = park.size();
    int w = park[0].length();
    for(int i = 0; i < park.size(); i++){
        for(int j = 0; j < park[i].length(); j++){
            if(park[i][j] == 'S'){
                start.push_back(i); //행
                start.push_back(j); //열
                break;
            }
        }
    }
    for(int i = 0; i < routes.size(); i++){
        int num = routes[i][2] - '0';  // 얼만큼 이동하는지 
        int moX = start[1]; //moveX
        int moY = start[0]; 
        bool flag = false;
        if(routes[i][0] == 'E'){
            if(-1 < moX + num && moX + num < w ){
                    flag = true;
                    moX += num;
                }
        }
        else if(routes[i][0] == 'W'){
            if(-1 < moX - num && moX - num < w ){
                    flag = true;
                    moX -= num;
                 }
        }
        else if(routes[i][0] == 'N'){
            if(-1 < moY - num && moY - num < h ){
                    flag = true;
                    moY -= num;
                 }
        }
        else if(routes[i][0] == 'S'){
            if(-1 < moY + num && moY + num < h ){
                    moY += num;
                    flag = true;
                }
        }
       
        if(flag){
            if(start[1] > moX){
                for(int j = moX; j <= start[1]; j++){
                    if(park[moY][j] == 'X'){
                        flag = false;
                        break;                        
                    }
                }
            }
            else if(start[1] < moX){
                for(int j = start[1]; j <= moX; j++){
                    if(park[moY][j] == 'X'){
                        flag = false;
                        break;                        
                    }
                }
            }
            else if(start[0] > moY){
                for(int j = moY; j <= start[0]; j++){
                    if(park[j][moX] == 'X'){
                        flag = false;
                        break;                        
                    }
                }
            }
             else if(start[0] < moY){
                for(int j = start[0]; j <= moY; j++){
                    if(park[j][moX] == 'X'){
                        flag = false;
                        break;                        
                    }
                }
            }
        }
        if(flag){
            start[0] = moY;
            start[1] = moX;
        }
    }
    answer.push_back(start[0]);
    answer.push_back(start[1]);
    return answer;
}