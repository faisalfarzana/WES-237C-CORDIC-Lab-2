open_component phasedetector.comp -reset
add_files [list phasedetector.cpp fir.cpp cordiccart2pol.cpp]
add_files -tb [list phasedetector_test.cpp]
set_top phasedetector
puts "Running: set_top phasedetector"
set_part xc7z020clg400-1
puts "Running: set_part xc7z020clg400-1"
create_clock -period 10ns
csynth_design

exit