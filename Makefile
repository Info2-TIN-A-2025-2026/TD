# ref directory template
TEMPLATE_DIR := TEMPLATE

.PHONY: $(shell ls)

# generic rule : make TDYYYYMMDD
%:
	@if [ -d "$@" ]; then \
		echo "❌ The directory '$@' already exists"; \
		exit 1; \
	fi
	@echo "📁 Creating '$@' from '$(TEMPLATE_DIR)' " 
	@mkdir "$@"
	@cp -r $(TEMPLATE_DIR)/* "$@"/
	@sed -i.bak 's/^.*put.*$$/\tput("$@");/' "$@/td.c"
	@rm -f "$@/td.c.bak"
	@git add "$@"
	@echo "✅ TD '$@' created and added to git"
