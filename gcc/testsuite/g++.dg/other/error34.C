// PR c++/46538
// { dg-do compile }
// { dg-options "" }

S () : str(__PRETTY_FUNCTION__) {}	// { dg-error "forbids declaration" "decl" }
// { dg-error "only constructors" "constructor" { target *-*-* } 5 }
// { dg-prune-output "__PRETTY_FUNCTION__" }
