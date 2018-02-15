	.name "Zilean"
	.comment "Up me plz"

	ld %0, r2
	zjmp %:fork

begin:	sti r3, r4, r2
	zjmp %-13

wall:	ldi %:begin, %0, r3
	ld %0, r2
	ld %0, r1
	zjmp %:begin

def:	ld %-8, r4
	fork %:wall
	
wall2:	ldi %:begin, %4, r3
	ld %4, r2
	ld %0, r1
	zjmp %:begin
	
fork:	fork %:live
fork2:	fork %:attack
	fork %:def
	fork %:fork2
	zjmp %:fork2

live:	st r1, 6
	live %42
	zjmp %:live

attack:	ldi %:end, %0, r3

end:	st r3, 256
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
