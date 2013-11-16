/* String is constructed with these four characters:
 * w - represents wolf 
 * s - represents sheep
 * . - represents empty space
 * # - represents fence
 * Write out how many sheeps have been slaughtered.
 *
 * For example:
 * #.wsw#s.s#.w#s.w.s#w
 * Only two sheeps in between fence #s.s# will survive.
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

using namespace std;
int howManySheepsHaveBeenEaten();
string genTerrain();
int roll(int min, int max);
void setChar(int num);
int loopBetweenFences(size_t, size_t, const string& );

string terrain;

int main(int argc, const char *argv[])
{
    srand(time(NULL));
    if (argc > 1) 
        terrain = argv[1];
    else 
        genTerrain();

    cout << "Slaughtered: " << howManySheepsHaveBeenEaten() << endl;
    
    return 0;
}

/* Idea: 
 * 1. Find postion of every fence - #. Store it in fence_pos_vector
 * 2. Loop through every char in string from begining to next occurance
 *    of fence - #.
 * 3. If there is one or more wolf - w, count the number of slaughtered
 *    sheeps.
 */
 
int howManySheepsHaveBeenEaten()
{
    int num_of_dead_sheeps=0;
    size_t fence_pos=0;
    std::vector<size_t> fence_pos_vector;

    if (terrain.find("#", fence_pos) != -1){
        for (int i = 0; i < terrain.length(); i++) {
            if (i == 0) {
                fence_pos = terrain.find("#",0);
                fence_pos_vector.push_back(fence_pos);
                i = fence_pos;
            }
            else {
                if (terrain.find("#", fence_pos+1) != -1){
                    fence_pos = terrain.find("#", fence_pos+1);
                    fence_pos_vector.push_back(fence_pos);
                    i = fence_pos;
                }
                else break;
            }
        }
    }
    else {
        fence_pos_vector.at(0) = 0;
    }

    for (int i = 0; i < fence_pos_vector.size(); i++) {
        if (i == 0) 
            num_of_dead_sheeps = loopBetweenFences(i, fence_pos_vector.at(i), terrain);
        
        // For not missing last sheep in this example: .sw#.sw#.sw
        else if (i == (fence_pos_vector.size() - 1)){
            num_of_dead_sheeps += loopBetweenFences(fence_pos_vector.at(i-1), 
                              fence_pos_vector.at(i) - fence_pos_vector.at(i-1), 
                              terrain);
            num_of_dead_sheeps += loopBetweenFences(fence_pos_vector.at(i), terrain.size(), terrain);
        }

        else
            num_of_dead_sheeps += loopBetweenFences(fence_pos_vector.at(i-1), 
                              fence_pos_vector.at(i) - fence_pos_vector.at(i-1),
                              terrain);
    }

    return num_of_dead_sheeps;
}

int loopBetweenFences(size_t start, size_t count, const string& terrain)
{
    int num_of_dead_sheeps = 0;
    string subterrain;
    size_t sheep_pos=0;
    vector<size_t> sheep_pos_vec;
    sheep_pos_vec.clear();
    subterrain = terrain.substr(start, count);
    
    cout << "fence: " << subterrain << endl;
    // if distance between fence is bigger then 1
    if ( subterrain.length() > 1)
        // if there is at least one wolf
        if (subterrain.find("w") != -1 ){
            for (int i = 0; i < subterrain.length(); i++) {
                if (subterrain.find("s",sheep_pos) != -1){
                    if (i == 0){ 
                        sheep_pos = subterrain.find("s",0);
                        sheep_pos_vec.push_back(sheep_pos);
                        i = sheep_pos;
                        num_of_dead_sheeps++;
                    }
                    else {
                        if (subterrain.find("s",sheep_pos+1) != -1){
                            sheep_pos = subterrain.find("s", sheep_pos+1);
                            sheep_pos_vec.push_back(sheep_pos);
                            i = sheep_pos;
                            num_of_dead_sheeps++;
                        }
                        else break;
                    }
                }
            }
        }

    // cout << "sheep pos vec: " << sheep_pos_vec.size() << endl;
    cout << "dead sheeps: " << num_of_dead_sheeps << endl;

    return num_of_dead_sheeps;
}

/* Idea, genarate a RAND number between 1 - 4
 * if 0 append . to terrain
 * if 1 append w to terrain
 * if 2 append s to terrain
 * if 3 append # to terrain
 */

string genTerrain()
{
    for (int i = 0; i < 4; i++) {
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
    cout << "terrain: " << terrain << endl;
    return terrain;
}

void setChar(int num){
    if (num == 0) terrain.append(".");
    if (num == 1) terrain.append("w");
    if (num == 2) terrain.append("s");
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
