package tree_sitter_nelua_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-nelua"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_nelua.Language())
	if language == nil {
		t.Errorf("Error loading Nelua grammar")
	}
}
