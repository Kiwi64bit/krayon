CC       := gcc
CFLAGS   := -Wall -Wextra -Wpedantic
CPPFLAGS := -I.

EXAMPLES_DIR := examples
EXAMPLES_BIN := build/examples
EXAMPLES_IMG := examples/images

EXAMPLES := $(basename $(notdir $(wildcard examples/*.c)))
BINARIES := $(addprefix $(EXAMPLES_BIN)/,$(EXAMPLES))

.DEFAULT_GOAL := examples

.PHONY: examples example-% list clean

$(EXAMPLES_BIN):
	mkdir -p $@

$(EXAMPLES_IMG):
	mkdir -p $@

$(EXAMPLES_BIN)/%: $(EXAMPLES_DIR)/%.c | $(EXAMPLES_BIN)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@

examples: $(addprefix example-,$(EXAMPLES))

example-%: $(EXAMPLES_BIN)/% | $(EXAMPLES_IMG)
	./$<

list-examples:
	@printf '%s\n' $(EXAMPLES)

clean:
	rm -rf $(EXAMPLES_BIN)
