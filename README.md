# Number-Guesser
Just wanted to make a small terminal game in C++, only works in windows (used the 'cls' command). Its pretty self explanatory and easy to play


## How to Compile

```
windres resource.rc -O coff -o resource.res
```

```
g++ main.cpp -o Guesser.exe resource.res -w -static -mconsole
```

## Screenshots

![Main Menue](https://i.imgur.com/cINhehq.png)

