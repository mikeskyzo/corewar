cd champions
for file in *.s
do
	echo "Testing champion $file ..."
	cp "$file" current.asm
	./asm current.asm
	../../asm current.asm test
	diff current.asm.cor test
	rm test
	rm current.asm
	rm current.asm.cor
done