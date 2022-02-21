#!/usr/bin/env python3

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

from PIL import Image