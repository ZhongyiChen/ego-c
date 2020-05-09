# Variables
BUILD_DIR = ./dist
CC = gcc
LD = gcc
LIB = -I zyc-libs/


# Common library
UTILS_OBJS = $(BUILD_DIR)/test_utils.o \
	$(BUILD_DIR)/utils.o

$(BUILD_DIR)/utils.o: zyc-libs/utils.c \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_utils.o: zyc-test/test_utils.c \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_utils.bin: $(UTILS_OBJS)
		$(LD) $^ -o $@


# Bubble sort files
BUBBLE_SORT_OBJS =	$(BUILD_DIR)/test_bubble_sort.o \
	$(BUILD_DIR)/bubble_sort.o \
	$(BUILD_DIR)/utils.o

$(BUILD_DIR)/test_bubble_sort.o: zyc-test/test_bubble_sort.c \
	algorithms/sort/bubble_sort.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/bubble_sort.o: algorithms/sort/bubble_sort.c \
	algorithms/sort/bubble_sort.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_bubble_sort.bin: $(BUBBLE_SORT_OBJS)
		$(LD) $^ -o $@


# Selection sort files
SELECTION_SORT_OBJS =	$(BUILD_DIR)/test_selection_sort.o \
	$(BUILD_DIR)/selection_sort.o \
	$(BUILD_DIR)/utils.o

$(BUILD_DIR)/test_selection_sort.o: zyc-test/test_selection_sort.c \
	algorithms/sort/selection_sort.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/selection_sort.o: algorithms/sort/selection_sort.c \
	algorithms/sort/selection_sort.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_selection_sort.bin: $(SELECTION_SORT_OBJS)
		$(LD) $^ -o $@


# Merge sort files
MERGE_SORT_OBJS =	$(BUILD_DIR)/test_merge_sort.o \
	$(BUILD_DIR)/merge_sort.o \
	$(BUILD_DIR)/utils.o

$(BUILD_DIR)/test_merge_sort.o: zyc-test/test_merge_sort.c \
	algorithms/sort/merge_sort.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/merge_sort.o: algorithms/sort/merge_sort.c \
	algorithms/sort/merge_sort.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_merge_sort.bin: $(MERGE_SORT_OBJS)
		$(LD) $^ -o $@


# Heap sort files
HEAP_SORT_OBJS =	$(BUILD_DIR)/test_heap_sort.o \
	$(BUILD_DIR)/heap_sort.o \
	$(BUILD_DIR)/utils.o

$(BUILD_DIR)/test_heap_sort.o: zyc-test/test_heap_sort.c \
	algorithms/sort/heap_sort.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/heap_sort.o: algorithms/sort/heap_sort.c \
	algorithms/sort/heap_sort.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_heap_sort.bin: $(HEAP_SORT_OBJS)
		$(LD) $^ -o $@


# Quick sort files
QUICK_SORT_OBJS =	$(BUILD_DIR)/test_quick_sort.o \
	$(BUILD_DIR)/quick_sort.o \
	$(BUILD_DIR)/utils.o

$(BUILD_DIR)/test_quick_sort.o: zyc-test/test_quick_sort.c \
	algorithms/sort/quick_sort.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/quick_sort.o: algorithms/sort/quick_sort.c \
	algorithms/sort/quick_sort.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_quick_sort.bin: $(QUICK_SORT_OBJS)
		$(LD) $^ -o $@


# Binary search files
BI_SEARCH_OBJS =	$(BUILD_DIR)/test_bi_search.o \
	$(BUILD_DIR)/bi_search.o \
	$(BUILD_DIR)/utils.o

$(BUILD_DIR)/test_bi_search.o: zyc-test/test_bi_search.c \
	algorithms/search/bi_search.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/bi_search.o: algorithms/search/bi_search.c \
	algorithms/search/bi_search.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_bi_search.bin: $(BI_SEARCH_OBJS)
		$(LD) $^ -o $@


# Bitree files
BI_TREE_OBJS = $(BUILD_DIR)/test_bi_tree.o \
	$(BUILD_DIR)/bi_tree.o \
	$(BUILD_DIR)/utils.o

$(BUILD_DIR)/test_bi_tree.o: zyc-test/test_bi_tree.c \
	data-structures/tree/bi_tree.h \
	zyc-libs/utils.h \
	zyc-libs/null.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/bi_tree.o: data-structures/tree/bi_tree.c \
	data-structures/tree/bi_tree.h \
	zyc-libs/null.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_bi_tree.bin: $(BI_TREE_OBJS)
		$(LD) $^ -o $@


# SinglyLinkedList files
SINGLY_LINKED_LIST_OBJS = $(BUILD_DIR)/test_singly_linked_list.o \
	$(BUILD_DIR)/singly_linked_list.o

$(BUILD_DIR)/test_singly_linked_list.o: zyc-test/test_singly_linked_list.c \
	data-structures/linked-list/singly_linked_list.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/singly_linked_list.o: data-structures/linked-list/singly_linked_list.c \
	data-structures/linked-list/singly_linked_list.h \
	zyc-libs/null.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_singly_linked_list.bin: $(SINGLY_LINKED_LIST_OBJS)
		$(LD) $^ -o $@


# DoublyLinkedList files
DOUBLY_LINKED_LIST_OBJS = $(BUILD_DIR)/test_doubly_linked_list.o \
	$(BUILD_DIR)/doubly_linked_list.o

$(BUILD_DIR)/test_doubly_linked_list.o: zyc-test/test_doubly_linked_list.c \
	data-structures/linked-list/doubly_linked_list.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/doubly_linked_list.o: data-structures/linked-list/doubly_linked_list.c \
	data-structures/linked-list/doubly_linked_list.h \
	zyc-libs/null.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_doubly_linked_list.bin: $(DOUBLY_LINKED_LIST_OBJS)
		$(LD) $^ -o $@


# FiniteStack files
FINITE_STACK_OBJS = $(BUILD_DIR)/test_finite_stack.o \
	$(BUILD_DIR)/finite_stack.o

$(BUILD_DIR)/test_finite_stack.o: zyc-test/test_finite_stack.c \
	data-structures/stack/finite_stack.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/finite_stack.o: data-structures/stack/finite_stack.c \
	data-structures/stack/finite_stack.h \
	zyc-libs/null.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_finite_stack.bin: $(FINITE_STACK_OBJS)
		$(LD) $^ -o $@


# InfiniteStack files
INFINITE_STACK_OBJS = $(BUILD_DIR)/test_infinite_stack.o \
	$(BUILD_DIR)/infinite_stack.o \
	$(BUILD_DIR)/singly_linked_list.o

$(BUILD_DIR)/test_infinite_stack.o: zyc-test/test_infinite_stack.c \
	data-structures/stack/infinite_stack.h \
	data-structures/linked-list/singly_linked_list.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/infinite_stack.o: data-structures/stack/infinite_stack.c \
	data-structures/stack/infinite_stack.h \
	data-structures/linked-list/singly_linked_list.h
	zyc-libs/null.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_infinite_stack.bin: $(INFINITE_STACK_OBJS)
		$(LD) $^ -o $@


# CircularQueue files
CIRCULAR_QUEUE_OBJS = $(BUILD_DIR)/test_circular_queue.o \
	$(BUILD_DIR)/circular_queue.o

$(BUILD_DIR)/test_circular_queue.o: zyc-test/test_circular_queue.c \
	data-structures/queue/circular_queue.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/circular_queue.o: data-structures/queue/circular_queue.c \
	data-structures/queue/circular_queue.h \
	zyc-libs/null.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_circular_queue.bin: $(CIRCULAR_QUEUE_OBJS)
		$(LD) $^ -o $@


# InfiniteQueue files
INFINITE_QUEUE_OBJS = $(BUILD_DIR)/test_infinite_queue.o \
	$(BUILD_DIR)/infinite_queue.o \
	$(BUILD_DIR)/doubly_linked_list.o

$(BUILD_DIR)/test_infinite_queue.o: zyc-test/test_infinite_queue.c \
	data-structures/queue/infinite_queue.h \
	data-structures/linked-list/doubly_linked_list.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/infinite_queue.o: data-structures/queue/infinite_queue.c \
	data-structures/queue/infinite_queue.h \
	data-structures/linked-list/doubly_linked_list.h
	zyc-libs/null.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_infinite_queue.bin: $(INFINITE_QUEUE_OBJS)
		$(LD) $^ -o $@


# HashMap files
HASH_MAP_OBJS = $(BUILD_DIR)/test_hash_map.o \
	$(BUILD_DIR)/hash_map.o \
	$(BUILD_DIR)/utils.o

$(BUILD_DIR)/test_hash_map.o: zyc-test/test_hash_map.c \
	data-structures/map/hash_map.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/hash_map.o: data-structures/map/hash_map.c \
	data-structures/map/hash_map.h \
	zyc-libs/null.h \
	zyc-libs/utils.h
		$(CC) -c $< -o $@

$(BUILD_DIR)/test_hash_map.bin: $(HASH_MAP_OBJS)
		$(LD) $^ -o $@


# Common commands
.PHONY: clean \
	mk_dir \
	compile_utils \
	test_utils \
	compile_bubble_sort \
	test_bubble_sort \
	compile_selection_sort \
	test_selection_sort \
	compile_merge_sort \
	test_merge_sort \
	compile_heap_sort \
	test_heap_sort \
	compile_quick_sort \
	test_quick_sort \
	compile_bi_search \
	test_bi_search \
	compile_bi_tree \
	test_bi_tree \
	compile_singly_linked_list \
	test_singly_linked_list \
	compile_doubly_linked_list \
	test_doubly_linked_list \
	compile_finite_stack \
	test_finite_stack \
	compile_infinite_stack \
	test_infinite_stack \
	compile_circular_queue \
	test_circular_queue \
	compile_infinite_queue \
	test_infinite_queue \
	compile_hash_map \
	test_hash_map \

clean:
	cd $(BUILD_DIR) && rm -f ./*

mk_dir:
	if [ ! -d $(BUILD_DIR) ];	then \
		mkdir $(BUILD_DIR); \
	fi


# Utils commands
compile_utils: $(BUILD_DIR)/test_utils.bin

test_utils:
	@make mk_dir > /dev/null
	@make compile_utils > /dev/null
	@$(BUILD_DIR)/test_utils.bin


# Bubble sort commands
compile_bubble_sort: $(BUILD_DIR)/test_bubble_sort.bin

test_bubble_sort:
	@make mk_dir > /dev/null
	@make compile_bubble_sort > /dev/null
	@$(BUILD_DIR)/test_bubble_sort.bin


# Selection sort commands
compile_selection_sort: $(BUILD_DIR)/test_selection_sort.bin

test_selection_sort:
	@make mk_dir > /dev/null
	@make compile_selection_sort > /dev/null
	@$(BUILD_DIR)/test_selection_sort.bin


# Merge sort commands
compile_merge_sort: $(BUILD_DIR)/test_merge_sort.bin

test_merge_sort:
	@make mk_dir > /dev/null
	@make compile_merge_sort > /dev/null
	@$(BUILD_DIR)/test_merge_sort.bin


# Heap sort commands
compile_heap_sort: $(BUILD_DIR)/test_heap_sort.bin

test_heap_sort:
	@make mk_dir > /dev/null
	@make compile_heap_sort > /dev/null
	@$(BUILD_DIR)/test_heap_sort.bin


# Quick sort commands
compile_quick_sort: $(BUILD_DIR)/test_quick_sort.bin

test_quick_sort:
	@make mk_dir > /dev/null
	@make compile_quick_sort > /dev/null
	@$(BUILD_DIR)/test_quick_sort.bin


# Binary search commands
compile_bi_search: $(BUILD_DIR)/test_bi_search.bin

test_bi_search:
	@make mk_dir > /dev/null
	@make compile_bi_search > /dev/null
	@$(BUILD_DIR)/test_bi_search.bin


# Bitree commands
compile_bi_tree: $(BUILD_DIR)/test_bi_tree.bin

test_bi_tree:
	@make mk_dir > /dev/null
	@make compile_bi_tree > /dev/null
	@$(BUILD_DIR)/test_bi_tree.bin


# SinglyLinkedList commands
compile_singly_linked_list: $(BUILD_DIR)/test_singly_linked_list.bin

test_singly_linked_list:
	@make mk_dir > /dev/null
	@make compile_singly_linked_list > /dev/null
	@$(BUILD_DIR)/test_singly_linked_list.bin


# DoublyLinkedList commands
compile_doubly_linked_list: $(BUILD_DIR)/test_doubly_linked_list.bin

test_doubly_linked_list:
	@make mk_dir > /dev/null
	@make compile_doubly_linked_list > /dev/null
	@$(BUILD_DIR)/test_doubly_linked_list.bin


# FiniteStack commands
compile_finite_stack: $(BUILD_DIR)/test_finite_stack.bin

test_finite_stack:
	@make mk_dir > /dev/null
	@make compile_finite_stack > /dev/null
	@$(BUILD_DIR)/test_finite_stack.bin


# InfiniteStack commands
compile_infinite_stack: $(BUILD_DIR)/test_infinite_stack.bin

test_infinite_stack:
	@make mk_dir > /dev/null
	@make compile_infinite_stack > /dev/null
	@$(BUILD_DIR)/test_infinite_stack.bin


# CircularQueue commands
compile_circular_queue: $(BUILD_DIR)/test_circular_queue.bin

test_circular_queue:
	@make mk_dir > /dev/null
	@make compile_circular_queue > /dev/null
	@$(BUILD_DIR)/test_circular_queue.bin


# InfiniteQueue commands
compile_infinite_queue: $(BUILD_DIR)/test_infinite_queue.bin

test_infinite_queue:
	@make mk_dir > /dev/null
	@make compile_infinite_queue > /dev/null
	@$(BUILD_DIR)/test_infinite_queue.bin


# HashMap commands
compile_hash_map: $(BUILD_DIR)/test_hash_map.bin

test_hash_map:
	@make mk_dir > /dev/null
	@make compile_hash_map > /dev/null
	@$(BUILD_DIR)/test_hash_map.bin