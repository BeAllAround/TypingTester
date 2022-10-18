#!/usr/bin/env node

function deep(base, ...rest) {
  let base_isf = 'function' === typeof base;
  let base_iso = null != base && ('object' === typeof base || base_isf);
  for (let over of rest) {
    let over_isf = 'function' === typeof over;
    let over_iso = null != over && ('object' === typeof over || over_isf);
    let over_ctor;
    if (base_iso &&
        over_iso &&
        !over_isf &&
        Array.isArray(base) === Array.isArray(over)) {
      for (let k in over) {
        base[k] = deep(base[k], over[k]);
      }
    }
    else {
      base =
        undefined === over
        ? base
        : over_isf
        ? over
        : over_iso
        ? 'function' === typeof (over_ctor = over.constructor) &&
        'Object' !== over_ctor.name &&
        'Array' !== over_ctor.name
        ? over
        : deep(Array.isArray(over) ? [] : {}, over)
      : over;
      base_isf = 'function' === typeof base;
      base_iso = null != base && ('object' === typeof base || base_isf);
    }
  }
  return base;
}

function tests() {
	// triggering 'RangeError: Maximum call stack size exceeded'
	// Consider merging Circular references
	let a1 = {a: 1,}
	a1.b = a1
	let a2 = {a: 2,}
	a2.b = a2
	console.log(deep(a1, a2))
}

/*
 * For a start, one way to avoid this is to check is obj[key] matches the 'obj' itself so,
 * // pseudo-code
 * for(key in source) {
 * 	if(key in dest) {
 * 		if((source[key] === dest[key]) && typeof source[key] == 'object' && typeof dest[key] == 'object') {
 * 			continue // ignore
 * 		}
 * 	}
 * }
 *  // However, I am not sure if this point is, at all, relevant as far as the deep_merge is concerned - please, let me know
 */


tests()
