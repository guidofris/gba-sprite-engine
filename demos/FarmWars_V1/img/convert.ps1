grit.exe FarmWar.bmp -gt -gB8 -mRtpf -mLs -ftc
rm ./FarmWar.h
rm ../sprites/startscreen.h
mv ./FarmWar.c ../sprites/startscreen.h

grit.exe bg_moon.png bg_mountain.png -gt -gB8 -mRtpf -mLs -ftc -pS -O bg_shared
mv -Force bg_moon.h ../sprites/bg_moon.h
mv -Force bg_moon.c ../sprites/bg_moon.c
mv -Force bg_mountain.h ../sprites/bg_mountain.h
mv -Force bg_mountain.c ../sprites/bg_mountain.c
mv -Force bg_shared.c ../sprites/bg_shared.c
mv -Force bg_shared.h ../sprites/bg_shared.h

grit.exe eend.png kip.png koe.png konijn.png lama.png yoda.png select.png turret.png -ftc -pS -gB8 -O shared.c
mv -Force eend.c ../sprites/eend.c
mv -Force eend.h ../sprites/eend.h

mv -Force kip.c ../sprites/kip.c
mv -Force kip.h ../sprites/kip.h

mv -Force koe.c ../sprites/koe.c
mv -Force koe.h ../sprites/koe.h

mv -Force konijn.c ../sprites/konijn.c
mv -Force konijn.h ../sprites/konijn.h

mv -Force lama.c ../sprites/lama.c
mv -Force lama.h ../sprites/lama.h

mv -Force yoda.c ../sprites/yoda.c
mv -Force yoda.h ../sprites/yoda.h

mv -Force select.c ../sprites/select.c
mv -Force select.h ../sprites/select.h

mv -Force turret.c ../sprites/turret.c
mv -Force turret.h ../sprites/turret.h

mv -Force shared.c ../sprites/shared.c
mv -Force shared.h ../sprites/shared.h
