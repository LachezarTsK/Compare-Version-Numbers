
/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function (version1, version2) {

    this.less = -1;
    this.greater = 1;
    this.equal = 0;

    const delimeter = "\.";
    const v1 = version1.split(delimeter);
    const v2 = version2.split(delimeter);
    const sizeShorter = Math.min(v1.length, v2.length);

    for (let i = 0; i < sizeShorter; i++) {
        let first = Number.parseInt(v1[i]);
        let second = Number.parseInt(v2[i]);
        if (first !== second) {
            return (first < second) ? less : greater;
        }
    }

    if (v1.length !== v2.length) {
        return (v1.length < v2.length) ? checkRemainder(v1, v2, this.less) : checkRemainder(v2, v1, this.greater);
    }
    return this.equal;
};


/**
 * @param {string[]} first
 * @param {string[]} second
 * @param {number} returnValueIfNonzeroElementIsFound
 * @return {number}
 */
function checkRemainder(first, second, returnValueIfNonzeroElementIsFound) {
    for (let i = first.length; i < second.length; i++) {
        if (Number.parseInt(second[i]) > 0) {
            return returnValueIfNonzeroElementIsFound;
        }
    }
    return this.equal;
}
