package lists.simulation;

import lists.SortedLinkedList;
import lists.coarse.SortedLinkedListCoarse;
import lists.utils.InputGenerator;
import lists.utils.Logger;
import org.junit.Test;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

/**
 * Created by Sebi on 02-Nov-17.
 */
public class Main {


    private static void runSimulation(){

        SortedLinkedList list = new SortedLinkedListCoarse();
        Logger logger = new Logger("E:\\Info\\anu3\\progr paralela\\labs\\ParallelProgrammingLabs\\lab3\\src\\lists\\simulation\\Results1.txt");
        logger.logOperation("Simulation started");

        List<Double> add1 = InputGenerator.getValuesInRange(10, 0, 10);
        List<Double> add2 = InputGenerator.getValuesInRange(5, 0, 10);
        List<Double> delete = InputGenerator.getValuesFromLists(7, add1, add2);

        List<Thread> threads = new LinkedList<>();
        threads.add(new Thread(new Inserter("T1", list, add1, logger, 1000L)));
        threads.add(new Thread(new Inserter("T2", list, add2, logger, 1000L)));
        threads.add(new Thread(new Remover("T3", list, delete, logger, 1000L)));
        Printer printer = new Printer("T4", list, 3000L, 5, logger);
        Thread printerTh = new Thread(printer);

        for (Thread t : threads){
            t.start();
        }
        printerTh.start();

        for (Thread t : threads){
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        // stop the printer thread after the rest
        printer.setRunning(false);
        try {
            printerTh.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    public static void main(String[] args) {
        runSimulation();
    }
}
