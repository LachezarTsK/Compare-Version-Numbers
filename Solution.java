
public class Solution {

    final static int LESS = -1;
    final static int GREATER = 1;
    final static int EQUAL = 0;
    final static String DELIMETER = "\\.";

    public int compareVersion(String version1, String version2) {

        String[] v1 = version1.split(DELIMETER);
        String[] v2 = version2.split(DELIMETER);
        final int sizeShorter = Math.min(v1.length, v2.length);

        for (int i = 0; i < sizeShorter; i++) {
            int first = Integer.parseInt(v1[i]);
            int second = Integer.parseInt(v2[i]);
            if (first != second) {
                return (first < second) ? LESS : GREATER;
            }
        }

        if (v1.length != v2.length) {
            return (v1.length < v2.length) ? checkRemainder(v1, v2, LESS) : checkRemainder(v2, v1, GREATER);
        }
        return EQUAL;
    }

    public int checkRemainder(String[] first, String[] second, int returnValueIfNonzeroElementIsFound) {
        for (int i = first.length; i < second.length; i++) {
            if (Integer.parseInt(second[i]) > 0) {
                return returnValueIfNonzeroElementIsFound;
            }
        }
        return EQUAL;
    }
}
