# Makefile dans le dossier src

# Définir les dossiers et leurs Makefiles respectifs
SUBDIRS = activation_fonction affichage passe_en_avant structures traitement_data

.PHONY: all clean $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done