void StrVec::free()
{
	if (elements) {
		for_each(elements, first_free, [this](string &rhs) {alloc.destroy(&rhs); });
		alloc.deallocate(elements, cap - elements);
	}
}