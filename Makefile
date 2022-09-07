BIN_DIR = exe
CXX = g++
CPPFLAGS = -Wall -g -Ilib

$(BIN_DIR)/split_test: src/split.o src/split_test.o lib/split.h
	$(CXX) $(CPPFLAGS) -c $* -o $@

$(BIN_DIR)/split.o: src/split.cpp lib/split.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)

$(BIN_DIR)/.dirstamp:
	mkdir -p $(BIN_DIR)
	touch $(BIN_DIR)/.dirstamp