TARGET=Crawler
INCLUDEPATH=../../include
LIBPATH=-L../../lib
INCLUDE=-I$(INCLUDEPATH)

# LIB 
LIBTBB=-ltbb -lrt 
LIBBOOST=-lpthread \
	-lboost_system \
	-lboost_filesystem \
	-lboost_regex \
	-lboost_serialization \
	-lboost_program_options \
	-lboost_date_time
LIBOTHERS=-lcppnetlib-uri \
	-lcppnetlib-client-connections  -lcrypto

LIBS=$(LIBTBB) $(LIBBOOST) $(LIBOTHERS)

#-L/usr/local/lib -L/usr/lib/x86_64-linux-gnu -lcurl
SRCRESS=main.cpp \
    urldownloader.cpp \
    httpheader.cpp \
    URL.cpp \
    httprequest.cpp \
    crawler.cpp \
    parser.cpp \
    httpasyncclient.cpp \
    urlregister.cpp \
    urlresolverclient.cpp \
    crawleddataprocessor.cpp

OBJRESS=$(subst .cpp,.o,$(SRCRESS))

# Implicit Rules
all: Crawler

Crawler: $(OBJRESS)
	$(CC) $(CFLAGS) $(OBJRESS) -o $@ $(INCLUDE) $(LIBPATH) $(LIBS)
	
%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm *.o
	rm $(TARGET)
