# Variables
BUILD_DIR = ./dist
CC = gcc
LD = gcc
LIB = -I zyc-libs/


# Common library
$(BUILD_DIR)/utils.o: zyc-libs/utils.c \
	zyc-libs/utils.h
		$(CC) -c $< -o $@


# Quick sort files
QUICK_SORT_RECUR_OBJS =	$(BUILD_DIR)/test_quick_sort_recur.o \
	$(BUILD_DIR)/quick_sort_recur.o \
	$(BUILD_DIR)/utils.o

$(BUILD_DIR)/test_quick_sort_recur.o: zyc-test/test_quick_sort_recur.c \
	algorithms/quick-sort/quick_sort_recur.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/quick_sort_recur.o: algorithms/quick-sort/quick_sort_recur.c \
	algorithms/quick-sort/quick_sort_recur.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_quick_sort_recur.bin: $(QUICK_SORT_RECUR_OBJS)
		$(LD) $^ -o $@


# Bitree files
BI_TREE_OBJS = $(BUILD_DIR)/test_bi_tree.o \
	$(BUILD_DIR)/bi_tree.o

$(BUILD_DIR)/test_bi_tree.o: zyc-test/test_bi_tree.c \
	data-structures/tree/bi_tree.h \
	data-structures/node/bi_node.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/bi_tree.o: data-structures/tree/bi_tree.c \
	data-structures/tree/bi_tree.h \
	data-structures/node/bi_node.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_bi_tree.bin: $(BI_TREE_OBJS)
		$(LD) $^ -o $@


# SinglyLinkedList files
SINGLY_LINKED_LIST_OBJS = $(BUILD_DIR)/test_singly_linked_list.o \
	$(BUILD_DIR)/singly_linked_list.o

$(BUILD_DIR)/test_singly_linked_list.o: zyc-test/test_singly_linked_list.c \
	data-structures/linked-list/singly_linked_list.h \
	data-structures/node/singly_linked_node.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/singly_linked_list.o: data-structures/linked-list/singly_linked_list.c \
	data-structures/linked-list/singly_linked_list.h \
	data-structures/node/singly_linked_node.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_singly_linked_list.bin: $(SINGLY_LINKED_LIST_OBJS)
		$(LD) $^ -o $@


# Common commands
.PHONY: clean \
	mk_dir \
	compile_quick_sort_recur \
	test_quick_sort_recur \
	compile_bi_tree \
	test_bi_tree \

clean:
	cd $(BUILD_DIR) && rm -f ./*

mk_dir:
	if [ ! -d $(BUILD_DIR) ];	then \
		mkdir $(BUILD_DIR); \
	fi


# Quick sort commands
compile_quick_sort_recur: $(BUILD_DIR)/test_quick_sort_recur.bin

test_quick_sort_recur:
	@make mk_dir > /dev/null
	@make compile_quick_sort_recur > /dev/null
	@$(BUILD_DIR)/test_quick_sort_recur.bin


# Bitree commands
compile_bi_tree: $(BUILD_DIR)/test_bi_tree.bin

test_bi_tree:
	@make mk_dir > /dev/null
	make compile_bi_tree
	$(BUILD_DIR)/test_bi_tree.bin


# SinglyLinkedList commands
compile_singly_linked_list: $(BUILD_DIR)/test_singly_linked_list.bin

test_singly_linked_list:
	@make mk_dir > /dev/null
	@make compile_singly_linked_list
	@$(BUILD_DIR)/test_singly_linked_list.bin