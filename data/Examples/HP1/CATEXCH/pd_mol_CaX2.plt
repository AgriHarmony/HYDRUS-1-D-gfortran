# G N U P L O T : template made by HP1-2.1.002 released on November 02, 2009
#
# Diederik Jacques and Jirka Simunek
#
# PROJECT FOLDER: C:\ussl\HYDRUS-1D v4\Examples\HP1\CATEXCH 
#
set border 31 front linetype -1 linewidth 1.000
set grid
set style increment default
set size ratio 0 1,1
set style data lines
set mxtics 2
set mytics 2
set xrange [*:*]
set xrange [*:*]
set xtics border out scale 3,1.5 nomirror norotate  offset character 0, 0.5, 0 autofreq
set ytics border out scale 2,1 nomirror norotate  offset character 0.5, 0, 0 autofreq
set title "" 
set title  offset character 0, 0, 0 font "" norotate
set timestamp bottom
set timestamp ""
set timestamp  offset character 0, 0, 0 font "" norotate
set xlabel  offset character 0, 1, 0 font "" textcolor lt -1 norotate
set xrange [ * : * ] noreverse nowriteback 
set ylabel  offset character 2, 0, 0 font "" textcolor lt -1 rotate by 90
set yrange [ * : * ] noreverse nowriteback
set zero 1e-008
GNUTERM = "win"
set key title
set key outside right top vertical Left reverse enhanced noautotitle nobox
set key noinvert samplen 2 spacing 1 width 0 height 0
set ylabel "Distance (cm)"
set xlabel "CaX2 (mol/kg water)"
set loadpath "C:\ussl\HYDRUS-1D v4\Examples\HP1\CATEXCH\"
plot 'nod_inf_chem.out' using 17:2 index 0:0 title "      0 days " linestyle 1 , \
     'nod_inf_chem.out' using 17:2 index 1:1 title "  0.50 days" linestyle 2 , \
     'nod_inf_chem.out' using 17:2 index 2:2 title "  1.00 days" linestyle 3 , \
     'nod_inf_chem.out' using 17:2 index 3:3 title "  3.00 days" linestyle 4 , \
     'nod_inf_chem.out' using 17:2 index 4:4 title "  9.00 days" linestyle 5 , \
     'nod_inf_chem.out' using 17:2 index 5:5 title " 15.00 days" linestyle 6 

# EOF