#
# BLYAT
#
# TEST FILE
#

.name "blyatman"
.comment "just a basic drinking slav"

begin:
ld %255, r2
ld %4, r3
ld %5, r4
sti r1, %:live, %1
lp:
sti r2, %:end, r4
live: live %1
add r3, r4, r4
and r5, %0, r5
end:
zjmp %:lp