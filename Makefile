
######################################
######################################

CXX=g++

CFLAGS=-Wall -c -O3

LDFLAGS=-Wall -O3

TARGETS = Beagle_GPIO.o	\
	  Beagle_AutoIrrigation \

all: $(TARGETS)

Beagle_GPIO.o: Beagle_GPIO.cc Beagle_GPIO.hh
	@echo Compiling $< to $@
	@$(CXX) $(CFLAGS) Beagle_GPIO.cc

Beagle_AutoIrrigation: Beagle_AutoIrrigation.cc Beagle_GPIO.o
	@echo Compiling $< to $@
	@$(CXX) $(LDLAGS) Beagle_AutoIrrigation.cc Beagle_GPIO.o -o Beagle_AutoIrrigation

clean:
	@rm -rf *~ *.o $(TARGETS) 


######################################
######################################

