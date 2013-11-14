## Sheep slaughtering - small fun program for counting characters

String is constructed with these four characters:
* w - represents wolf 
* s - represents sheep
* . - represents empty space
* # - represents fence

Write out how many sheeps have been slaughtered.

### For example:

* #.vov#o.o#.v#o.v.o#v

Only two sheeps in between fence #o.o# will survive.


### Old broken version output:

 Starting program: /home/maki/a.out 
 ov.#o.#v#ov.v.#oo.v#
 Slaughtered: 3
 [Inferior 1 (process 14706) exited normally]
 (gdb) r
 Starting program: /home/maki/a.out 
  #.ov#v.oo.#v.ov#v.o#
 Slaughtered: 4
 [Inferior 1 (process 14709) exited normally]
 (gdb) r
 Starting program: /home/maki/a.out 
 o#v.o.#vv#o.#v.o#vo.
 Slaughtered: 2
 [Inferior 1 (process 14710) exited normally]
 (gdb) r
 Starting program: /home/maki/a.out 
  #.voo.v#.v#ov.o#vo.#
 Slaughtered: 4
 [Inferior 1 (process 14711) exited normally]

