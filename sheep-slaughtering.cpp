/* String is constructed with these four characters:
 * w - represents wolf 
 * s - represents sheep
 * . - represents empty space
 * # - represents fence
 * Write out how many sheeps have been slaughtered.
 *
 * For example:
 * #.vov#o.o#.v#o.v.o#v
 * Only two sheeps in between fence #o.o# will survive.
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;
int howManySheepsHaveBeenEaten();
string genTerrain();
int roll(int min, int max);
void setChar(int num);

string terrain;

int main( )
{
    srand(time(NULL));

    genTerrain();
    cout << "Slaughtered: " << howManySheepsHaveBeenEaten() << endl;

    return 0;
}
int howManySheepsHaveBeenEaten()
{
    int num_of_dead_sheeps=0;
    string fight;
    size_t wolf_pos, sheep_pos, space_pos;
    int j=0, dist=0;
    for (int i = 0; i < terrain.length(); i++) {
        j++;
        fight += terrain.at(i);
        if (j % 4 == 0) {
            wolf_pos = fight.find("v");
            sheep_pos = fight.find("o");
            dist = abs (wolf_pos - sheep_pos);
            // cout << wolf_pos << endl;
            // cout << sheep_pos << endl;
            // cout << dist << endl;
            if (dist == 1) num_of_dead_sheeps++;
            if (dist == 2) {
                if (wolf_pos > sheep_pos) {
                    if (fight.at(wolf_pos - 1) == '.') 
                        num_of_dead_sheeps++;
                }
                else {
                    if (fight.at(sheep_pos - 1) == '.')
                        num_of_dead_sheeps++;
                }
            }
        }
        
        if (j % 4 == 0) fight.erase(fight.begin(), fight.end());
    }

    return num_of_dead_sheeps;
}

/* Idea, genarate a RAND number between 1 - 4
 * if 0 append . to terrain
 * if 1 append v to terrain
 * if 2 append o to terrain
 * if 3 append # to terrain
 */

string genTerrain()
{
    for (int i = 0; i < 5; i++) {
        int first = roll(0,3);
        setChar(first);

        int second = roll(0,3);
        while (second == first){ 
            second = roll(0,3);
            if (second != first) break;
        }
        setChar(second);

        int third = roll(0,3);
        while ((third == first) || (third == second)){
            third = roll(0,3);
            if ((third != first) && (third != second)) break;
        }
        setChar(third);
        
        int fourth = roll(0,3);
        while (1){
            fourth = roll(0,3);
            if ((fourth != first) && (fourth != second) && (fourth != third)) break;
        }
        setChar(fourth);

    }
    cout << terrain << endl;
    return terrain;
}

void setChar(int num){
    if (num == 0) terrain.append(".");
    if (num == 1) terrain.append("v");
    if (num == 2) terrain.append("o");
    if (num == 3) terrain.append("#");
}
    

int roll(int min, int max)
{
   // x is in [0,1[
   double x = rand()/static_cast<double>(RAND_MAX); 

   // [0,1[ * (max - min) + min is in [min,max[
   int that = min + static_cast<int>( x * (max - min + 1) );

   return that;
}
