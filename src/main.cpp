#include<iostream>
using namespace std;

#include "enigma.h"

int main(){
    freopen("src/input.txt","r",stdin);
    freopen("src/output.txt","w",stdout);

    string rotors;
    cin>>rotors;

    vector<int> initstates(3);
    for(int i=0;i<3;i++)
        cin>>initstates[i];

    int n;
    cin>>n;

    vector<pair<int,int>> plugs(10);
    for(int i=0;i<n;i++)
        cin>>plugs[i].first>>plugs[i].second;

    int width,height;
    cin>>width>>height;

    cout<<width<<" "<<height<<"\n";

    Enigma enigma;
    enigma.setup(rotors,initstates,plugs);

    enigma.height=height;
    enigma.width=width;

    enigma.convert();
}
