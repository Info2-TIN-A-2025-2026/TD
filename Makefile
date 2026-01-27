# Répertoire template
TEMPLATE_DIR := TEMPLATE

# Par défaut, empêcher make de croire que TDxxxx est un fichier
.PHONY: $(shell ls)

# Règle générique : make NOM_DU_TD
%:
	@if [ -d "$@" ]; then \
		echo "❌ Le dossier '$@' existe déjà"; \
		exit 1; \
	fi
	@echo "📁 Création du TD '$@'"
	@mkdir "$@"
	@cp -r $(TEMPLATE_DIR)/* "$@"/
	@git add "$@"
	@echo "✅ TD '$@' créé et ajouté à git"
