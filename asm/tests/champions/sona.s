	.name "sona"
	.comment "Op in ARAM"

	ld %0, r2
des:	zjmp %:start
	live %42

wall:	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	st r2, -510
	st r3, -511
	zjmp %:wall
	
def:	ldi %:live1, %5, r2
	ldi %:live1, %9, r3
	ld %0, r1
	zjmp %:wall

start:	sti r2, %:des, %0
	sti r2, %:des, %4
	fork %:live

fork:	fork %:att
	fork %:def

fork2:	fork %:fork
	zjmp %:fork2
	

live:	st r1, 6
	live %42
	fork %:live1
	fork %:live2
	fork %:live3
	
live1:	st r1, 6
	live %42
	zjmp %:live1

live2:	st r1, 6
	live %42
	zjmp %:live2

live3:	st r1, 6
	live %42
	zjmp %:live3
	
att:	ldi %:end1, %0, r3

end1:	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
	st r3, 256
