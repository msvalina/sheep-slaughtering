## Sheep slaughtering - small fun program for counting characters

A string is constructed with these four characters:
* w - represents wolf 
* s - represents sheep
* . - represents empty space
* # - represents fence

Write out how many sheeps have been slaughtered.

### For example:

* #.wsw#s.s#.w#s.w.s#w

Only two sheeps in between fence #s.s# will survive.


### Program output:

    (gdb) r
    Starting program: /home/maki/geek/source/sheep-slaughtering/a.out 
    terrain: sw#.s#w..w#ss.w#
    fence: sw
    dead sheeps: 1
    fence: #.s
    dead sheeps: 0
    fence: #w..w
    dead sheeps: 0
    fence: #ss.w
    dead sheeps: 2
    fence: #
    dead sheeps: 0
    Slaughtered: 3

### Reminder to myself - what I learned

* This is the first program that I used ```gdb``` on. I successfully debugged four
annoying bugs, and I'm sure that it would had taken ages if I didn't use 
```gdb```.

* Finally figured why ```const type &``` are useful.
