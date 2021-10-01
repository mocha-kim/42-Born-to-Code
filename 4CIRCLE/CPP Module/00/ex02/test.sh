./account > my.log
sed -i ' ' -e 's/20......_....../19920104_091532/g' my.log
diff 19920104_091532.log my.log
rm my.log