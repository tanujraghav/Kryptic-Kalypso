#!/usr/bin/env python3

if __name__ != "__main__":
  exit()

VERSION = "1.0.0"

BANNER = f"""   \x1b[48;5;16m\x1b[38;5;196m    ██ ▄█▀██▀███▓██   ██▓██▓███ ▄▄▄█████▓██▓▄████▄     \33[0m
   \x1b[48;5;16m\x1b[38;5;196m    ██▄█▒▓██ ▒ ██▒██  ██▓██░  ██▓  ██▒ ▓▓██▒██▀ ▀█     \33[0m
   \x1b[48;5;16m\x1b[38;5;160m   ▓███▄░▓██ ░▄█ ▒▒██ ██▓██░ ██▓▒ ▓██░ ▒▒██▒▓█    ▄    \33[0m
   \x1b[48;5;16m\x1b[38;5;160m   ▓██ █▄▒██▀▀█▄  ░ ▐██▓▒██▄█▓▒ ░ ▓██▓ ░░██▒▓▓▄ ▄██▒   \33[0m
   \x1b[48;5;16m\x1b[38;5;160m   ▒██▒ █░██▓ ▒██▒░ ██▒▓▒██▒ ░  ░ ▒██▒ ░░██▒ ▓███▀ ░   \33[0m
   \x1b[48;5;16m\x1b[38;5;124m   \x1b[1;38;5;21m\x1b[48;5;46mTanuj Raghav\x1b[38;5;124m\x1b[48;5;16m▒▓░ ██▒▒▒▒▓▒░ ░  ░ ▒ ░░  ░▓ ░ ░▒ ▒  ░   \33[0m
   \x1b[48;5;16m\x1b[38;5;124m   ░ ░▒ ▒░ ░▒ ░ ▒▓██ ░▒░░▒ ░        ░    ▒ ░ ░  ▒      \33[0m
   \x1b[48;5;16m\x1b[38;5;124m   ░ ░░ ░  ░░   ░▒ ▒ ░░ ░░        ░      ▒ ░           \33[0m
   \x1b[48;5;16m\x1b[38;5;124m   ░  ░     ░    ░ ░                     ░ ░ ░         \33[0m
   \x1b[48;5;16m\x1b[38;5;88m                 ░ ░                       ░           \33[0m
   \x1b[48;5;16m\x1b[38;5;88m  ██ ▄█▄▄▄      ██▓  ▓██   ██▓██▓███   ██████ ▒█████   \33[0m
   \x1b[48;5;16m\x1b[38;5;88m  ██▄█▒████▄   ▓██▒   ▒██  ██▓██░  ██▒██    ▒▒██▒  ██▒ \33[0m
   \x1b[48;5;16m\x1b[38;5;88m ▓███▄▒██  ▀█▄ ▒██░    ▒██ ██▓██░ ██▓░ ▓██▄  ▒██░  ██▒ \33[0m
   \x1b[48;5;16m\x1b[38;5;88m ▓██ █░██▄▄▄▄██▒██░    ░ ▐██▓▒██▄█▓▒ ▒ ▒   ██▒██   ██░ \33[0m
   \x1b[48;5;16m\x1b[38;5;52m ▒██▒ █▓█   ▓██░██████▒░ ██▒▓▒██▒ ░  ▒██████▒░ ████▓▒░ \33[0m
   \x1b[48;5;16m\x1b[38;5;52m ▒ ▒▒ ▓▒▒   ▓▒█░ ▒░▓  ░ ██▒▒▒▒▓▒\x1b[1;38;5;46m\x1b[48;5;21mKryptic Kalypso v{VERSION}\x1b[38;5;52m\x1b[48;5;16m \33[0m
   \x1b[48;5;16m\x1b[38;5;52m ░ ░▒ ▒░▒   ▒▒ ░ ░ ▒  ▓██ ░▒░░▒ ░    ░ ░▒  ░ ░ ░ ▒ ▒░  \33[0m
   \x1b[48;5;16m\x1b[38;5;52m ░ ░░ ░ ░   ▒    ░ ░  ▒ ▒ ░░ ░░      ░  ░  ░ ░ ░ ░ ▒   \33[0m
   \x1b[48;5;16m\x1b[38;5;52m ░  ░       ░  ░   ░  ░ ░                  ░     ░ ░   \33[0m
   \x1b[48;5;16m\x1b[38;5;52m                      ░ ░                              \33[0m"""

import argparse, os, pathlib, re, subprocess, sys
from src import backend
from PIL import Image

class ArgumentParser():
  def init():
    parser = argparse.ArgumentParser(
      usage = f"""\33[1;20m%(prog)s\33[0m [-h] [-v]
       -i|--infile <filepath>
       [-d|--decrypt] [-o|--outfile <filepath>]""",
      description = f"""An Enigma Cipher based Image Steganography and Encryption System\nwith Linear Bit-wise Compression.\n\n{BANNER}""",
      epilog = "Designed and Developed by \33[1;20mTanuj Raghav\33[0m <\33[4;20mraghavtanuj.official@gmail.com\33[0m>",
      formatter_class = ArgumentParser.Formatter,
      add_help = False
    )

    arg_grp = parser.add_argument_group("")

    arg_grp.add_argument("-h", "--help", action = "help", help = "show this help message and exit")
    arg_grp.add_argument("-v", "--version", action = "version", version = f"%(prog)s {VERSION}")

    arg_grp = parser.add_argument_group("\33[1;20mREQUIRED\33[0m:")

    arg_grp.add_argument("-i", "--infile", type = pathlib.Path, required = True, metavar = " INFILE", help = "read image from INFILE")

    arg_grp = parser.add_argument_group("\33[1;20mOPTIONAL\33[0m:")

    arg_grp.add_argument("-d", "--decrypt", action = "store_true", help = "set system status to DECRYPTION (default = ENCRYPTION)")
    arg_grp.add_argument("-o", "--outfile", type = pathlib.Path, metavar = "OUTFILE", help = "write modified image to OUTFILE")

    return parser.parse_args()

  class Formatter(argparse.HelpFormatter):
    def _fill_text(self, text, width, indent):
      return "".join(indent + line for line in text.splitlines(keepends=True))

    def _format_action_invocation(self, action):
      i = []
      for j in action.option_strings:
          i.append(j)

      return ", ".join(i) + " " + self._format_args(action, self._get_default_metavar_for_optional(action))
    
    class _Section(argparse.HelpFormatter._Section):
      def format_help(self):
        join = self.formatter._join_parts
        item_help = join([func(*args) for func, args in self.items])

        if not item_help:
            return ""

        if self.heading != "==SUPPRESS==" and self.heading is not None:
          heading = "%*s%s\n" % (self.formatter._current_indent, "", self.heading)
        else:
          heading = ""

        return join(["\n", heading, item_help, "\n"])

class FrontEnd():
  def __init__(self):
    self.args = ArgumentParser.init()

    infile = self.args.infile

    if not os.path.exists(infile):
      exit(f"\33[1;20m{sys.argv[0]}\33[0m: [FileNotFoundError] - no such file or directory: {infile}")

    try:
      self.img = Image.open(infile)
      self.w, self.h = self.img.size
      if self.img.format != "PNG":
        exit()
    except:
      exit(f"\33[1;20m{sys.argv[0]}\33[0m: [UnsupportedFileFormatError] - unsupported file format, please check if it's an PNG image: {infile}")

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
    backend.init(infile,file)

    print(">>> Encrypting Image...")
    subprocess.call(["./src/encrypt.out"])

    print(">>> Saving Encrypted Image...")
    self.output(infile)

    os.remove("src/input.txt")
    os.remove("src/output.txt")

    print(">>> Done!")

  def output(self, path):
    file = open(f"src/output.txt", "r")

    w, h = file.readline().split()

    s = int(w), int(h)

    img = Image.new("RGB", s, "black")
    p = img.load()

    for a in range(s[0]):
      for b in range(s[1]):
        p[a,b] = tuple([int(k) for k in file.readline().split()])

    x = self.args.outfile if self.args.outfile else self.args.infile
    y = "-decrypted" if self.args.decrypt else "-encrypted"

    img.save(os.path.splitext(x)[0] + y + os.path.splitext(x)[1], 'png')

FrontEnd()