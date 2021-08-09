#!/usr/bin/env python3

def main():
    path=input(">>> File Path: ")
    if not os.path.exists(path):
        exit("Error 404: File not found")

    rotors=input(">>> Rotor Setting: ")
    if not re.match(r'^[1-8]{3}[b-c]{1}[B-C]{1}$',rotors):
        exit("Error: Invalid rotor settings")

    initstate=input(">>> Rotor Initial State: ")
    i=tuple(initstate.split())
    if int(min(i))<0 or int(max(i))>255 or len(i)!=3:
        exit("Error: Invalid rotor initial states")

    plugs=input(">>> Plugboard Setting: ")
    j=tuple(plugs.split())
    if int(min(j))<0 or int(max(j))>255 or len(j)>20 or len(j)%2!=0 or len(j)!=len(set(j)):
        exit("Error: Invalid plug settings")

    file=open("src/input.txt","w")
    file.write(rotors+"\n")
    file.write(initstate+"\n")
    file.write(str(int(len(j)/2))+"\n"+plugs+"\n")

    print(">>> Processing Image...")
    backend.init(path,file)

    print(">>> Encrypting Image...")
    subprocess.call(["./src/encrypt.out"])

    print(">>> Saving Encrypted Image...")
    backend.save(path)

    os.remove("src/input.txt")
    os.remove("src/output.txt")

    print(">>> Done!")

from src import backend
import re, os, subprocess
main()
