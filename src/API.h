#ifndef EnigmaM4
#define EnigmaM4

#include<string>
#include<vector>

using namespace std;

class Enigma {
    private:
        vector<pair<int,int>> rotors=vector<pair<int,int>>(3);
        vector<int> reflectors=vector<int>(2);

        vector<int> turnpoint={123,184,116,219,38,231,140,62};

        vector<pair<int,int>> plugs=vector<pair<int,int>>(10);

        int pixel;

        void swapPlugs();
        void substitution();

        vector<vector<int>> rot=vector<vector<int>>(3);
        vector<vector<int>> ref=vector<vector<int>>(2);

        void init();

        void rotate(vector<int> &vec,int n);
        void rotate();

        void forward();
        void backward();
    public:
        int height,width;
        void setup(string rotors,vector<int> initstate,vector<pair<int,int>> plugs);
        void convert();
};

#endif
