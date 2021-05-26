echo -n 'Executable: '
read INPUT

make ${INPUT}
echo -n 'File Size: '
du -sh ${INPUT}/main
./${INPUT}/main