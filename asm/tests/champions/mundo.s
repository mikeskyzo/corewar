	.name "Mundo"
	.comment "Mundo will go where he pleases! (slurps)"

	ld %0, r2
	zjmp %:startl

begin1:	sti r3, r4, r2
	zjmp %-85

begin2:	sti r3, r4, r2
	zjmp %-85

begin3:	sti r3, r4, r2
	zjmp %-85

begin4:	sti r3, r4, r2
	zjmp %-85

begin5:	sti r3, r4, r2
	zjmp %-85

begin6:	sti r3, r4, r2
	zjmp %-85

begin7:	sti r3, r4, r2
	zjmp %-85

begin8:	sti r3, r4, r2
	zjmp %-85

begin9:	sti r3, r4, r2
	zjmp %-85

begin10: sti r3, r4, r2
	zjmp %-85

wall:	fork %:begin1
	fork %:begin2
	fork %:begin3
	fork %:begin4
	fork %:begin5
	fork %:begin6
	fork %:begin7
	fork %:begin8
	fork %:begin9
	fork %:begin10
	fork %:wall
	zjmp %:wall

def2:	ldi %:begin10, %0, r3
	ld %0, r2
	ld %0, r1
	zjmp %:wall

def:	ld %-80, r4
	fork %:def2

	ldi %:begin10, %4, r3
	ld %4, r2
	ld %0, r1
	zjmp %:wall
startl:	fork %:live

fork:	fork %:att
	fork %:def
fork2:	fork %:fork
	zjmp %:fork2

live:	st r1, 6
	live %42
	zjmp %:live

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
