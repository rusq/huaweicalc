CXX      = g++
OPENSSL  := $(shell brew --prefix openssl 2>/dev/null || echo /usr/local)
CXXFLAGS = -O2 -Wall -I$(OPENSSL)/include
LDFLAGS  = -L$(OPENSSL)/lib -lcrypto
TARGET   = huaweicalc_cli

SRCS = main_cli.cpp \
       calc.cpp \
       encrypt_1.cpp \
       encrypt_2.cpp \
       encrypt_3.cpp \
       encrypt_4.cpp \
       encrypt_5_v2.cpp \
       encrypt_6.cpp \
       encrypt_7.cpp \
       encrypt_v1.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
