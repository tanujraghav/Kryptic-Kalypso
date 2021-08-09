#include "API.h"

void Enigma::setup(string rotors,vector<int> initstate,vector<pair<int,int>> plugs){
    for(int i=0;i<3;i++){
        this->rotors[i].first=rotors[i]-49;
        this->rotors[i].second=initstate[i];
    }

    this->reflectors[0]=rotors[3]-98;
    this->reflectors[1]=rotors[4]-64;

    for(int i=0;i<plugs.size();i++){
        this->plugs[i].first=plugs[i].first;
        this->plugs[i].second=plugs[i].second;
    }
}

void Enigma::swapPlugs(){
    for(int j=0;j<this->plugs.size();j++)
        if(this->pixel==plugs[j].first){
            this->pixel=plugs[j].second;
            break;
        }
        else if(this->pixel==plugs[j].second){
            this->pixel=plugs[j].first;
            break;
        }
}

void Enigma::convert(){
    init();
    int buff;
    for(int i=0;i<this->height*this->width;i++){
        for(int j=0;j<3;j++){
            cin>>buff;
            this->pixel=buff;
            swapPlugs();
            substitution();
            swapPlugs();
            cout<<this->pixel<<" ";
        }
        cout<<endl;
    }
}
