package tests;

import matrix.types.ComplexNumberElem;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Sebi on 21-Oct-17.
 */
public class ComplexNumberElemTest {
    @Test
    public void add() throws Exception {
        ComplexNumberElem c1 = new ComplexNumberElem(2, 3);
        ComplexNumberElem c2 = new ComplexNumberElem(3, -1.5);
        ComplexNumberElem res = (ComplexNumberElem)c1.add(c2);
        assertTrue(res.getA() == 5);
        assertTrue(res.getB() == 1.5);

    }

    @Test
    public void multiply() throws Exception {
        ComplexNumberElem c1 = new ComplexNumberElem(2, 3);
        ComplexNumberElem c2 = new ComplexNumberElem(3, -1.5);
        ComplexNumberElem res = (ComplexNumberElem)c1.multiply(c2);
        assertTrue(res.getA() == 10.5);
        assertTrue(res.getB() == 6);
    }

}