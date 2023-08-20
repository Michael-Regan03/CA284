#include <stdio.h>
#include <stdlib.h> 



int main(int argc, char * argv[]){
    int try, conversion, penalty, drop_goal, points;
    int t_multiplier = 5;
    int c_multiplier = 2;
    int p_multiplier = 3;
    int dg_multiplier = 3;
    try = atoi(argv[1]);
    conversion = atoi(argv[2]);
    penalty = atoi(argv[3]);
    drop_goal = atoi(argv[4]);
    points = (try*t_multiplier)+(conversion*c_multiplier)+(penalty*p_multiplier)+(drop_goal*drop_goal);
    printf("%d\n",points);
    return 0;

}
