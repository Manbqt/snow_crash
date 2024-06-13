# Level09

In this level we have an executable and a file named `token`.  
We have tried the program to understand it:

```bash
level09@SnowCrash:~$ ./level09 aaa
abc
level09@SnowCrash:~$ ./level09 123
135
```

With these examples, we can see that the string is changed. For each char we add the index at the value to obtain the new value. `(new_str[i] = str[i] + i)`  
As we have seen previously, we have a file named token. We can guess that the output of this file is the result of program called.  
So we have write a [script](./resources/script.py) in python to reverse the content.  

```bash
level09@SnowCrash:~$ python /tmp/script.py token 
('Token: ', 'f3iji1ju5yuevaus41q1afiuq')
level09@SnowCrash:~$ su flag09
Password: 
Don't forget to launch getflag !
flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```
