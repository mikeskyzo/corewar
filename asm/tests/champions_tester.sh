cd champions
for file in *.s
do
	echo "Testing champion $file ..."
	cp "$file" current.asm
	cp current.asm current2.asm
	./asm current.asm
	../../asm current2.asm
	diff current.asm.cor current2.asm.cor
	rm test
	rm current.asm
	rm current2.asm
	rm current.asm.cor
	rm current2.asm.cor
done