CXX     = g++     # the c compiler to use
CXXFLAGS = -std=c++14        # common defines
FLTK   = -lfltk -lfltk_images	# fltk libs
FLTK_LOCATION = ../fltk/

<<<<<<< HEAD
FLTK_OBJS = Graph.o GUI.o Simple_window.o Window.o Splash_window.o How_to_window.o High_score_window.o Track_scores.o Map_window.o My_Window.o Finish_window.o output.o
=======
FLTK_OBJS = Graph.o GUI.o Simple_window.o Window.o Splash_window.o How_to_window.o High_score_window.o Track_scores.o Map_window.o My_Window.o Finish_window.o distance.o
>>>>>>> origin/master

HW_BINS = Main

all: $(HW_BINS)

clean:
	rm $(FLTK_OBJS) $(HW_BINS)

# ==== FLTK LIBRARY ====
Graph.o: $(FLTK_LOCATION)/Graph.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
GUI.o: $(FLTK_LOCATION)/GUI.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
Simple_window.o: $(FLTK_LOCATION)/Simple_window.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
Window.o: $(FLTK_LOCATION)/Window.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Splash_window.o: $(FLTK_LOCATION)/Splash_window.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

How_to_window.o: $(FLTK_LOCATION)/How_to_window.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

High_score_window.o: $(FLTK_LOCATION)/High_score_window.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Track_scores.o: $(FLTK_LOCATION)/Track_scores.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
Map_window.o: $(FLTK_LOCATION)/Map_window.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
My_Window.o: $(FLTK_LOCATION)/My_Window.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
Finish_window.o: $(FLTK_LOCATION)/Finish_window.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

<<<<<<< HEAD
output.o: $(FLTK_LOCATION)/output.cpp
=======
distance.o: $(FLTK_LOCATION)/distance.cpp
>>>>>>> origin/master
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# ==== HOMEWORK FILES ====
Main: Main.cpp $(FLTK_OBJS)
	$(CXX) $(CXXFLAGS) $(FLTK) -o $@ $(FLTK_OBJS) Main.cpp
