BUILD_DIR = ./dist
CC = gcc
LD = gcc
LIB = -I zyc-libs/
CCFLAGS = 
LDFLAGS = 

QUICK_SORT_RECUR_OBJS =	$(BUILD_DIR)/test_quick_sort_recur.o						\
												$(BUILD_DIR)/quick_sort_recur.o									\
												$(BUILD_DIR)/utils.o

$(BUILD_DIR)/test_quick_sort_recur.o: zyc-test/test_quick_sort_recur.c		\
																			quick-sort/quick_sort_recur.h			\
																			zyc-libs/utils.h
	$(CC) -c $< -o $@

$(BUILD_DIR)/quick_sort_recur.o: quick-sort/quick_sort_recur.c					\
																 quick-sort/quick_sort_recur.h					\
																 zyc-libs/utils.h
	$(CC) -c $< -o $@

$(BUILD_DIR)/utils.o: zyc-libs/utils.c																			\
											zyc-libs/utils.h
	$(CC) -c $< -o $@

$(BUILD_DIR)/test_quick_sort_recur.bin: $(QUICK_SORT_RECUR_OBJS)
	$(LD) -o $@ $^

.PHONY: clean \
				mk_dir \
				compile_quick_sort_recur \
				test_quick_sort_recur

clean:
	cd $(BUILD_DIR) && rm -f ./*

mk_dir:
	if [ ! -d $(BUILD_DIR) ];	then																				\
		mkdir $(BUILD_DIR);																									\
	fi

compile_quick_sort_recur: $(BUILD_DIR)/test_quick_sort_recur.bin

test_quick_sort_recur:
	@make mk_dir > /dev/null
	@make compile_quick_sort_recur > /dev/null
	@$(BUILD_DIR)/test_quick_sort_recur.bin