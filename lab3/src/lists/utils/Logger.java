package lists.utils;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;

/**
 * Created by Sebi on 02-Nov-17.
 */
public class Logger {
    private String filePath;

    public Logger(String filePath) {
        this.filePath = filePath;
    }

    public synchronized void logOperation(String operation){
        Date now = new Date();
        operation = now.toString() + " " + operation;

        try(FileWriter fw = new FileWriter(filePath, true);
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter out = new PrintWriter(bw))
        {
            out.println(operation);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
