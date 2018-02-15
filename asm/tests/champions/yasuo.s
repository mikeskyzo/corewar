	.name "yasuo"
	.comment "Nerf me plz"

	ld %0, r2
	zjmp %:start
	
wall:	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	st r2, -468
	st r3, -469
	zjmp %:wall
	
def:	ldi %:live1, %5, r2
	ldi %:live1, %9, r3
	ld %0, r1
	zjmp %:wall

start:	fork %:live

fork:	fork %:def
	fork %:att

fork2:	fork %:fork
	zjmp %:fork2
	

live:	st r1, 6
	live %42
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
	
att:	ld %80, r4
	fork %:sec
	ld %0, r2
	ldi %:end1, %0, r3
	ld %0, r1
	zjmp %:torp

sec:	ld %4, r2
	ldi %:end1, %4, r3
	ld %0, r1
	zjmp %:torp

torp:	fork %:end1
	fork %:end2
	fork %:end3
	fork %:end4
	fork %:end5
	fork %:end6
	fork %:end7
	fork %:end8
	fork %:end9
	fork %:end10
	fork %:torp
	zjmp %:torp

end1:	sti r3, r4, r2
	zjmp %75

end2:	sti r3, r4, r2
	zjmp %75

end3:	sti r3, r4, r2
	zjmp %75

end4:	sti r3, r4, r2
	zjmp %75

end5:	sti r3, r4, r2
	zjmp %75

end6:	sti r3, r4, r2
	zjmp %75

end7:	sti r3, r4, r2
        zjmp %75

end8:	sti r3, r4, r2
        zjmp %75

end9:	sti r3, r4, r2
        zjmp %75

end10:	sti r3, r4, r2
        zjmp %75
