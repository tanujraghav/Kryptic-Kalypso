#!/usr/bin/env python3

def createImage(width,height,file):
    encrypted=Image.new("RGB",(width,height),"black")

    pixels=encrypted.load()

    for i in range(width):
        for j in range(height):
            line=file.readline()
            r,g,b=line.split()
            pixels[i,j]=(int(r),int(g),int(b))

    return encrypted

def getPixels(image,file):
    width,height=image.size

    for i in range(width):
        for j in range(height):
            p=image.getpixel((i,j))
            file.write(str(p[0])+" "+str(p[1])+" "+str(p[2])+"\n")

def init(path,file):
    original=Image.open(path)

    file.write(str(original.size[0])+" "+str(original.size[1])+"\n")

    getPixels(original,file)

def save(path):
    file=open("src/output.txt","r")
    
    line=file.readline()
    width,height=line.split()

    encrypted=createImage(int(width),int(height),file)
    encrypted.save(os.path.splitext(path)[0]+'.Encrypted'+os.path.splitext(path)[1],'png')

from PIL import Image
import os