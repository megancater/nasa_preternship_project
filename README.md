# Nasa Preternship Project - Memory Optimization
#### Mason Porter, Megan Cater, Francesca Schena, Drew Curtin

This proof-of-concept program takes in a .txt file (created from the python executables) and
determines the most memory-optimzed data structure to store that data in, depending on user
input. The progam then outputs a simple display to visualize the selected data structure.

To run:
1. Execute one of the two python progams in the src/ folder:
 - weather.py - Outputs weather data in file named 'weather_data.txt'
 - carbon.oy  - Outputs carbon data in file named 'carbon_data.txt'
2. Run 'make main_test' in the main project folder to create the program executable
3. Run './exe/main_test' with the text file as the second argument
4. Follow the steps shown by the program
5. Watch the program's results!
 - NOTE: the memory threshold for the first question should be entered in BYTES, not kB or MB
