GIT_HOOK := .git/hooks/applied
$(GIT_HOOK): scripts/install-git-hooks
	@$<
	@echo

.PHONY: all check clean
all: $(GIT_HOOK) check
.DEFAULT_GOAL := all

CFLAGS = -I./include
CFLAGS += -std=c99 -pedantic -Wall -W -Werror -MD -MP

TESTS = \
    containerof \
    list_entry \
    list_init-explicit \
    list_init-local \
    list_init-global \
    list_add \
    list_add_tail \
    list_del \
    list_del_init \
    list_first_entry \
    list_last_entry \
    list_is_singular \
    list_for_each_safe \
    list_for_each_entry_safe \
    list_for_each \
    list_for_each_entry \
    list_move \
    list_move_tail \
    list_splice \
    list_splice_tail \
    list_splice_init \
    list_splice_tail_init \
    list_cut_position

TESTS := $(addprefix tests/,$(TESTS))

# tests flags and options
CFLAGS += -std=c99 -pedantic -Wall -W -Werror -MD -MP

# verbose output switch
ifneq ($(findstring $(MAKEFLAGS),s),s)
ifndef V
	Q_CC = @echo '    CC' $@;
	Q_LD = @echo '    CC' $@;
	export Q_CC
	export Q_LD
endif
endif

COMPILE.c = $(Q_CC)$(CC) -x c $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
LINK.o = $(Q_LD)$(CC) $(CFLAGS) $(LDFLAGS) $(TARGET_ARCH)

TESTS_OK = $(TESTS:=.ok)

check: $(TESTS_OK)

$(TESTS_OK): %.ok: %
	@echo ">>  CC$(TESTRUN_NAME) $<"
	@$(TESTRUN_WRAPPER) ./$<
	@touch $@

# standard build rules
.SUFFIXES: .o .c
.c.o:
	$(COMPILE.c) -o $@ $<

$(TESTS): %: %.o
	$(LINK.o) $^ $(LDLIBS) -o $@

clean:
	@$(RM) $(TESTS) $(deps) $(TESTS_OK) $(TESTS:=.o) $(TESTS:=.d)

deps = $(TESTS:=.d)
-include $(deps)
